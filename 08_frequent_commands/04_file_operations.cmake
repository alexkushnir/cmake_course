file(DOWNLOAD https://alexkushnir.github.io/cmake_course index.html)
file(READ index.html FILE_CONTENT)
message("File content is ${FILE_CONTENT}")
file(REMOVE index.html)
