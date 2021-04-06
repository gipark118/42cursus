#!/bin/sh

tar -xvf /phpmyadmin.tar.gz > /dev/null
rm -rf /phpmyadmin.tar.gz
mv /custom-pma /var/www/pma
mkdir /var/www/pma/tmp
chmod -R 777 /var/www/pma/tmp

php-fpm7 && nginx -g "daemon off;"
