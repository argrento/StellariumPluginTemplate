# StellariumPluginTemplate 

Startpoint for the dynamic plugin development. Based on the HelloStelModule plugin. 

## Building the plugin

**Tested with:** Qt5.3, cmake 2.8.12.2, Stellarium 0.14.0, Ubuntu 14.04. 
Other operating systems are NOT yet supported.

0. Set all variables
   ```    
    QTDIR=Path to Qt (/opt/Qt5/5.3/gcc_64)
    QTPATH=Path to Qt (/opt/Qt5/5.3/gcc_64)
    PATH=Path to Qt binaries (/opt/Qt5/5.3/gcc_64/bin)$:${PATH}
    LD_LIBRARY_PATH=${QTPATH}/lib:${LD_LIBRARY_PATH}
   ```

1.  Install and build the SVN version of Stellarium as per the 
instructions on the Stellarium wiki:

  http://stellarium.org/wiki/index.php/Compilation_on_Linux

2.  Set the environment variable STELROOT to the root of the Stellarium
source tree.  The Stellarium build directory is expected to be:

   ```
    $STELROOT/builds/unix 
   ```

3.  Create a sub-directory builds/unix and change into that directory. 

4.  Run:

   ```
    cmake ../.. 
    make
    make install
   ```
   
If all goes well, the relevant files should be built and copied to your 
~/.stellarium/modules directory.


