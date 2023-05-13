protoc.exe --proto_path=./ --csharp_out=../csharp_output/ *.proto --csharp_opt=base_namespace=Protocol
IF ERRORLEVEL 1 PAUSE