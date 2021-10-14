#!/bin/bash

# This file will install the required dependencies for Debian/Ubuntu based systems
# No need to run this as root, as sudo will do it for you

readonly installedPackage="Status: install ok installed"

readonly ubuntuId="ID=ubuntu"
readonly debianId="ID=debian"
readonly mintId="ID=linuxmint"
# Define a bunch of constants to eliminate magic values


function distro {
	cat /etc/os-release | grep "\bID="
}
# Grab the user's distro

function checkDep() {
	dpkg -s $1 | grep "Status: install ok installed"
}
# Check if an input package is properly installed

function checkDistro() {
	if [[ `distro` == $ubuntuId || `distro` == $debianId || `distro` == $mintId ]]; then
		echo 1
	fi
}
# Check the user's distro against supported IDs

if [[ `checkDistro` -eq 1 ]]; then	
	buildEssential=`checkDep "build-essential"`
	qtBase=`checkDep "qtbase5-dev"`
	qMake=`checkDep "qt5-qmake"`
	# Store the result of checkDep against the dependencies for later use

	if [[ $buildEssential == $installedPackage && $qtBase == $installedPackage && $qMake == $installedPackage ]]; then
		# Check if each dependency is properly installed

		echo "All necessary packages already installed!"
		else
			echo "Install necessary packages? [Y/n]: "
			read inpt
			if [[ $inpt == "y" || $inpt == "Y" ]]; then
				# If the user agrees to installing the dependencies, check each individually and install them if they're missing
				
				if [[ $buildEssential != $installedPackage ]]; then
					echo "===== Installing 'build-essential' ====="
					sudo apt-get install --install-recommends build-essential -y
					echo "===== build-essential installed! ====="
				fi
				if [[ $qtBase != $installedPackage ]]; then
					echo "===== Installing 'qtbase5-dev' ====="
					sudo apt-get install --install-recommends qtbase5-dev -y
					echo "===== qtbase5-dev installed! ====="
				fi
				if [[ $qMake != $installedPackage ]]; then
					echo "===== Installing 'qt5-qmake' ====="
					sudo apt-get install --install-recommends qt5-qmake -y
					echo "===== qt5-qmake installed! ====="
				fi
			fi
	fi
else
	echo "Your system is unsuppored by this script. You will need to manually check for and install package dependencies"
	echo "If you're running a Debian/Ubuntu based distro but got this error anyway, use 'sudo apt install build-essential qtbase5-dev qt5-qmake' to get the dependencies"
	# Inform the user of distro incompatabilities with the script, and how to fix it if they're using a Debian/Ubuntu flavored distro
fi
