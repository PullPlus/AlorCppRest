#!/bin/bash
rm -rf AlorCppRest
libname=AlorCppRest
libnamel=alor
mkdir ${libname} && cd ${libname}
~/.openapi-generator/bin/openapi-generator-cli generate -i ../WarpOpenAPIv2.yml -g cpp-restsdk --additional-properties apiPackage=${libnamel}api --additional-properties modelPackage=${libnamel}model #--additional-properties packageName=${libnamelc}
find . -type f -name '*' -exec sed -i -r s/CppRestOpenAPIClient/${libname}/g {} +
mv ./include/CppRestOpenAPIClient ./include/${libname}
