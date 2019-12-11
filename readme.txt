CREATE DATABASE supermarket;
USE Resturant;
CREATE TABLE customers(
  id int(11) NOT NULL AUTO_INCREMENT,
  name varchar(100) DEFAULT NULL,
  phone varchar(11) DEFAULT NULL,
  address text,
  is_special int(1) DEFAULT NULL,
  PRIMARY KEY (id),
  UNIQUE KEY phone_UNIQUE (phone)
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
  PRIMARY KEY (`id`)
); 
 
