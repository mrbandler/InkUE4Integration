rem Build the plugin
call RunUAT.bat BuildPlugin -Plugin="%CD%\inkUE4Integration.uplugin" -Package="%CD%\Build\inkUE4Integration" -Rocket

rem Zip the plugin
rd /s /q "./Build/inkUE4Integration/Intermediate"
7z a ./Build/TwitchAuth.zip ./Build/TwitchAuth/*