#! /bin/sh

mkdir icezmq

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

sudo apt-get -y install libace-dev 
sudo apt-get -y install libssl-dev 
sudo apt-get -y install git
sudo apt-get -y install libzmq-dev
sudo apt-get -y install libzmqpp-dev

sudo apt-get update

echo "cd icezmq" >> build.sh

echo "wget https://dl.dropboxusercontent.com/u/57191386/zeromq-4.0.5-msvc2013-build-snapshot-20150404.zip" >> build.sh
echo "wget https://dl.dropboxusercontent.com/u/57191386/ACE-6.3.1.zip" >> build.sh
echo "wget https://dl.dropboxusercontent.com/u/57191386/Ice-3.5.1-3.msi" >> build.sh

echo "git clone https://github.com/INNOAUS/icezmq.git" >> build.sh
echo "tar cvfz icezma.tgz ./icezmq/*" >> build.sh

echo "cd icezmq/icezmq" >> build.sh

echo "make" >> build.sh
chmod +x build.sh

