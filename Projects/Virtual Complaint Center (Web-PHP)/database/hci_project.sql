-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 02, 2014 at 08:50 PM
-- Server version: 5.5.32
-- PHP Version: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `hci_project`
--
CREATE DATABASE IF NOT EXISTS `hci_project` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `hci_project`;

-- --------------------------------------------------------

--
-- Table structure for table `users_complaints`
--

CREATE TABLE IF NOT EXISTS `users_complaints` (
  `token_no` int(45) NOT NULL AUTO_INCREMENT,
  `full_name` varchar(45) NOT NULL,
  `email_id` varchar(45) NOT NULL,
  `category` varchar(45) NOT NULL,
  `complaint` varchar(250) NOT NULL,
  `comp_status` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`token_no`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10000003 ;

--
-- Dumping data for table `users_complaints`
--

INSERT INTO `users_complaints` (`token_no`, `full_name`, `email_id`, `category`, `complaint`, `comp_status`) VALUES
(10000001, 'heera lal', 'k112147@nu.edu.pk', 'Agriculture', 'Sindh Condition is very bad, please help us!', 'in process.'),
(10000002, 'Narain Sagar', 'k112368@nu.edu.pk', 'Education', 'I want to meet Zardari.!', 'in process.');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
