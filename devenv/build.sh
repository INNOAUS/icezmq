cd icezmq

#wget https://dl.dropboxusercontent.com/u/57191386/zeromq-4.0.5-msvc2013-build-snapshot-20150404.zip
#wget https://dl.dropboxusercontent.com/u/57191386/ACE-6.3.1.zip
#wget https://dl.dropboxusercontent.com/u/57191386/Ice-3.5.1-3.msi

git clone https://github.com/INNOAUS/icezmq.git
cd ..
tar cvfz icezma.tgz ./icezmq/*

cd icezmq/icezmq

make

