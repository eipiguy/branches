sourceDir=$1
buildDir=$2

# Configure
cmake -S $sourceDir -B $buildDir/linux

# Build
cmake --build $buildDir/linux