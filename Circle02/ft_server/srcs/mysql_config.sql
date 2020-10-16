use mysql;
flush privileges;
create database if not exists wordpress;
create user if not exists 'gipark'@'localhost' identified by '1201';
grant all privileges on wordpress.* to 'gipark'@'localhost';
use wordpress;
flush privileges;
