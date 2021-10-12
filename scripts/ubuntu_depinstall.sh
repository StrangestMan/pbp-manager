#!/bin/bash

# This file will install the required dependencies for Debian/Ubuntu based systems
# No need to run this as root, as sudo will do it for you

function distro {
	cat /etc/os-release | grep "\bID="
}

function checkDep() {
	dpkg -s $1 | grep "Status: install ok installed"
}

if [[ $(distro) == "ID=ubuntu" || $(distro) == "ID=debian" ]]; then
	buildEssential=`checkDep "build-essential"`
	qtBase=`checkDep "qtbase5-dev"`
	qMake=`checkDep "qt5-qmake"`

	if [[ $buildEssential == "Status: install ok installed" && $qtBase == "Status: install ok installed" && $qMake == "Status: install ok installed" ]]; then
		echo "All necessary packages already installed!"
		else
			echo "Install necessary packages? [Y/n]: "
			read inpt
			if [[ $inpt == "y" || $inpt == "Y" ]]; then
				if [[ $buildEssential != "Status: install ok installed" ]]; then
					echo "Installing 'build-essential'"
					sudo apt-get install --install-recommends build-essential -y
					clear && echo "build-essential installed!"
				fi
				if [[ $qtBase != "Status: install ok installed" ]]; then
					echo "Installing 'qtbase5-dev'"
					sudo apt-get install --install-recommends qtbase5-dev -y
					clear && echo "qtbase5-dev installed!"
				fi
				if [[ $qMake != "Status: install ok installed" ]]; then
					echo "Installing 'qt5-qmake'"
					sudo apt-get install --install-recommends qt5-qmake -y
					clear && echo "qt5-qmake installed!"
				fi
			fi
	fi
else
	echo "Your system is unsuppored by this script. You will need to manually check for and install package dependencies"
	echo "If you're running a Debian/Ubuntu based distro but got this error anyway, use 'sudo apt install build-essential qtbase5-dev qt5-qmake' to get the dependencies"
fi
