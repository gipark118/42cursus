use mysql;
flush privileges;
CREATE DATABASE IF NOT EXISTS wordpress;
create user if not exists 'gipark'@'localhost' identified by '1201';
grant all privileges on wordpress.* to 'gipark'@'localhost';
use wordpress;
flush privileges;
