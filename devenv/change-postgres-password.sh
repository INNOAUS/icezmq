#!/bin/sh

sudo -u postgres psql -U $1 -d $2 -c "alter user postgres with password '$3';"
# but it's possible with su too, this should work:
#su - postgres -c "psql -U postgres -d postgres -c \"alter user postgres with password 'password';\""
