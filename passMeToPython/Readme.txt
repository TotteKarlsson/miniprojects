In order to get a proper Python module, regarding static vs dynamic runtime, the 
Windows-Embarcadero.cmake file was modified. 

The modified file is Windows-Embarcadero.cmake. Put it into Cmakes 
\Program Files\CMake\share\cmake-3.8\Modules\Platform
folder. Backup original file if you wish.

The modified file causes all targets being built using borlands dynamic runtime. 
