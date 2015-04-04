#! /bin/sh

sudo apt-get -y install wget

sudo rm /etc/apt/sources.list.d/ice3.5-trusty.list

wget http://www.zeroc.com/download/RPM-GPG-KEY-zeroc-release
sudo apt-key add RPM-GPG-KEY-zeroc-release

cd /etc/apt/sources.list.d
sudo wget http://www.zeroc.com/download/Ice/3.5/ubuntu/ice3.5-trusty.list
sudo apt-get update
sudo apt-get -y install ice icebox/trusty-zeroc icegrid/trusty-zeroc
sudo apt-get -y install ice-dev
sudo apt-get -y install db5.3-util
#apt-get source ice3.5
#sudo apt-get -y install libmcpp-dev libbz2-dev 

sudo apt-get -y install make
sudo apt-get -y install g++

sudo apt-get -y install vim ssh unzip bzip2 htop ufw

sudo apt-get -y install libcrypto++-dev 
sudo apt-get -y install sqlite3 
sudo apt-get -y install libsqlite3-dev 
sudo apt-get -y install libboost-all-dev 
sudo apt-get -y install libpq-dev 
sudo apt-get -y install libace-dev 
sudo apt-get -y install libssl-dev 
sudo apt-get -y install libnet1-dev 
sudo apt-get -y install libpcap-dev 
sudo apt-get -y install libqrencode-dev 
sudo apt-get -y install libpam0g-dev 
sudo apt-get -y install libxerces-c-dev 
sudo apt-get -y install libxerces-c-doc 
sudo apt-get -y install subversion 
sudo apt-get -y install openssl 
sudo apt-get -y install nodejs-dev 
sudo apt-get -y install npm 
sudo apt-get -y install node-node-uuid 
sudo apt-get -y install node-gyp 
sudo apt-get -y install nodejs-legacy 
sudo apt-get -y install rlwrap

sudo apt-get -y libopencv-dev

sudo apt-get -y install openjdk-6-jdk

sudo apt-get -y install unixODBC unixodbc-dev freetds-dev sqsh tdsodbc

sudo apt-get -y install mono-complete

# run on a shell
# npm install -g packages.json
# npm install -g pg
# npm install -g colors
# npm install -g express

sudo apt-get -y install python-software-properties
sudo apt-get -y install postgresql-contrib-9.3
sudo apt-get update
