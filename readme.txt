This program requires mysql installed on your computer download mysql form this link https://dev.mysql.com/downloads/installer/
then make sure mysql server is running 
add mysql server to your system variables path
log into your mysql in terminal using this command:
mysql -u root -p
---you will be asked for your root user password if you want to login using different user change root to the wanted user

copy the following section to your terminal
-----------------------------------------------------------------------------------
CREATE USER 'supermarket917356'@'localhost' IDENTIFIED BY '917356';
GRANT ALL PRIVILEGES ON * . * TO 'supermarket917356'@'localhost';
FLUSH PRIVILEGES;
CREATE DATABASE supermarket917356;
USE supermarket917356;
CREATE TABLE `customers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `phone` varchar(11) DEFAULT NULL,
  `address` text,
  `is_special` int(1) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `phone_UNIQUE` (`phone`)
);
CREATE TABLE `items` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `selling_price` float DEFAULT NULL,
  `buying_price` float DEFAULT NULL,
  `quantity` float DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
);
CREATE TABLE `sellings` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `phone` varchar(11) DEFAULT NULL,
  `sellings` text,
  `date_time` datetime DEFAULT CURRENT_TIMESTAMP,
  `price` float DEFAULT NULL,
  `profit` float DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `phone` (`phone`),
  CONSTRAINT `sellings_ibfk_1` FOREIGN KEY (`phone`) REFERENCES `customers` (`phone`)
);
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `phone` varchar(11) DEFAULT NULL,
  `username` varchar(100) DEFAULT NULL,
  `password` varchar(100) DEFAULT NULL,
  `is_admin` int(1) DEFAULT (0),
  PRIMARY KEY (`id`),
  UNIQUE KEY `username_UNIQUE` (`username`)
);
CREATE TABLE `promocodes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `code` varchar(100) DEFAULT NULL,
  `discount` float DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `code_UNIQUE` (`code`)
);
-----------------------------------------------------------------------------------
Creating accounts section:
To creat admin account type the following in the terminal and put the wanted values in the here areas


insert into supermarket917356.users(name,phone,username,password,is_admin) values("name here","phone number here","username here",md5("password here"),1);


----------------------------------------------------------------------------
To creat non admin account type the following in the terminal and put the wanted values in the here areas



insert into supermarket917356.users(name,phone,username,password,is_admin) values("name here","phone number here","username here",md5("password here"),0);


-----------------------------------------------------------------------------------
That's it you are all set !

 
