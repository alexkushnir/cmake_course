#pragma once 

#include <format>
#include <string>
#include <string_view>
#include <cstdint>
#include <map>

namespace protocol
{
    class LogMessage
    {
    public:
        enum class LogSeverity : std::uint8_t
        {
            FATAL, ERROR, WARNING, INFO, DEBUG, TRACE
        };

        explicit LogMessage(const LogSeverity severity, const std::string& message) noexcept
            : m_severity{ severity }
            , m_message{ message}
        {}

        auto GetSeverity() const { return m_severity; }
        auto GetMessage() const { return m_message; }
    
    private: 
        LogSeverity m_severity;
        std::string m_message;
    };
}

template <>
struct std::formatter<protocol::LogMessage> 
{
public:
    constexpr auto parse(std::format_parse_context& ctx)
    {
        return ctx.begin();
    }

    auto format(const protocol::LogMessage& msg, std::format_context& ctx) const 
    {
        
        return std::format_to(ctx.out(), "{}: {}", SeverityToText(msg.GetSeverity()), msg.GetMessage());
    }

private:
    std::string_view SeverityToText(const protocol::LogMessage::LogSeverity severity) const
    {
        const std::map<protocol::LogMessage::LogSeverity, const std::string_view> severityToText
        { 
            { protocol::LogMessage::LogSeverity::FATAL, "FATAL" },
            { protocol::LogMessage::LogSeverity::ERROR, "ERROR" },
            { protocol::LogMessage::LogSeverity::WARNING, "WARNING" },
            { protocol::LogMessage::LogSeverity::INFO, "INFO" },
            { protocol::LogMessage::LogSeverity::DEBUG, "DEBUG" },
            { protocol::LogMessage::LogSeverity::TRACE, "TRACE" },
        };    

        return severityToText.at(severity);
    }
};