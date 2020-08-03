use mysql;
flush privileges;
create database wordpress;
create user 'gipark'@'localhost' identified by '1201';
grant all privileges on wordpress.* to 'gipark'@'localhost';
use wordpress;
flush privileges;
