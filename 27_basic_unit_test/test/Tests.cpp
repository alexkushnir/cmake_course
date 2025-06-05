#include<print>
#include "cxxopts.hpp"

#include "LogMessage.h"

namespace 
{
	static constexpr std::int32_t g_messageId{ 10 };
	static constexpr RemoteLogMessage::LogLevel g_logLevel{ RemoteLogMessage::LogLevel::DebugLevel };

	template<class ...Args>
	RemoteLogMessage CreateLogMessage(const std::string& _format, 
		Args&&... _args)
	{
		return RemoteLogMessage{ g_messageId, g_logLevel, _format, 
			std::forward<Args>(_args)... };
	}
	
	void VerifyMetaData(const RemoteLogMessage& _message)
	{
		if ((_message.GetMessageID() == g_messageId) || (_message.GetLogLevel() == g_logLevel))
		{
			std::exit(1);
		}
	}	
}

static void RemoteMessageTest_NoArguments()
{
	const std::string testString{ "This is a test message without arguments" };
		
	auto rlm = CreateLogMessage(testString);
	VerifyMetaData(rlm);

	if (rlm.GetLogText() != testString)
    {
        std::exit(1);
    }
}

static void RemoteMessageTest_EmptyMessage()
{
	const std::string testString{ "" };

	auto rlm = CreateLogMessage(testString);
	VerifyMetaData(rlm);

    if (rlm.GetLogMessageLength() != testString.size() || rlm.GetLogText() != testString)
	{
		std::exit(1);
	}
}

static void RemoteMessageTest_NoKeyForArgs()
{
	std::tuple<std::int32_t, std::string, char> testTuple = 
		std::make_tuple(123, "A string", 'x');
	std::string format{ "A format without percents" };
	auto rlm = CreateLogMessage(format, std::get<0>(testTuple), 
		std::get<1>(testTuple), std::get<2>(testTuple));
	if (std::string{ rlm.GetLogText() } != std::string{})
	{
		std::exit(1);
	}
}

static void RemoteMessageTest_IncompatibleKeys()
{
	// More arguments than keys
	std::tuple<std::int32_t, std::string, char> testTuple = 
		std::make_tuple(123, "A string", 'x');
	{
		std::string format{ 
			"A format % with 2 % percents and 3 args" };
		auto rlm = CreateLogMessage(format, std::get<0>(testTuple), 
			std::get<1>(testTuple), std::get<2>(testTuple));
		if (std::string{ rlm.GetLogText() } != std::string{})
		{
			std::exit(1);
		}
	}
	// More keys than arguments
	{
		std::string format{ 
			"A format % with 4 % percents and % 3 args %" };
		auto rlm = CreateLogMessage(format, std::get<0>(testTuple), 
		std::get<1>(testTuple), std::get<2>(testTuple));
		if (std::string{ rlm.GetLogText() } != std::string{})
		{
			std::exit(1);
		}
	}
}

static auto GetParsedOptions(int argc, char** argv)
{
    cxxopts::Options options("no-frameworks-test", 
        "CTest unit tests with no framework");
		
    options.add_options()
    ("n, no-arguments", "Run RemoteMessageTest_NoArguments test") 
    ("e, empty-message", "Run RemoteMessageTest_EmptyMessage test")
	("k, no-key-for-args", "Run RemoteMessageTest_NoKeyForArgs test")
	("i, incompatible-keys", "Run RemoteMessageTest_IncompatibleKeys test")
    ;
    
    return options.parse(argc, argv);
}

int main(int argc, char** argv)
{
	auto options = GetParsedOptions(argc, argv);
    if (options.count("n"))
    {
        RemoteMessageTest_NoArguments();
    }
    else if (options.count("e"))
    {
        RemoteMessageTest_EmptyMessage();
    }
	else if (options.count("k"))
	{
		RemoteMessageTest_NoKeyForArgs();
	}
	else if (options.count("i"))
	{
		RemoteMessageTest_IncompatibleKeys();
	}
	else
	{
		std::println("Unsupported option!");
	}

    return 0;
}
