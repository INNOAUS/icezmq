#! /bin/sh

sudo port selfupdate

sudo port install ace +universal
sudo port install libnet11 +universal
sudo port install libpcap +universal
sudo port install xercesc3 +universal
sudo port install libcryptopp +universal
sudo port install sqlite3 +universal
sudo port install postgresql93 +universal
sudo port install libpqxx +universal

sudo port upgrade outdated
