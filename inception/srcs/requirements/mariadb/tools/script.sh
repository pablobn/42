#!/bin/bash

service mariadb start;
mysql -u root --password=$DB_ROOT_PWD -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
mysql -u root --password=$DB_ROOT_PWD -e "CREATE USER IF NOT EXISTS '$DB_USER'@'localhost' IDENTIFIED BY '$DB_PWD';"
mysql -u root --password=$DB_ROOT_PWD -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO $DB_USER@'%' IDENTIFIED BY '$DB_PWD';"
# mysql -u root --password=$DB_ROOT_PWD -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PWD';"
mysql -u root --password=$DB_ROOT_PWD -e "FLUSH PRIVILEGES;"
mysqladmin -u root --password=$DB_ROOT_PWD shutdown
exec mysqld_safe
