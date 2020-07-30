use mysql;
flush privileges;
create user gipark identified by '1201';
grant all privileges on wordpress.* to 'gipark'@'localhost';
flush privileges;
