-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 06, 2014 at 04:57 PM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `hcidatabase`
--

-- --------------------------------------------------------

--
-- Table structure for table `logindb`
--

CREATE TABLE IF NOT EXISTS `logindb` (
  `username` varchar(17) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `logindb`
--

INSERT INTO `logindb` (`username`, `password`) VALUES
('k112147', 'fast'),
('k112148', 'fast1'),
('admin', 'fastadmin');

-- --------------------------------------------------------

--
-- Table structure for table `logintable`
--

CREATE TABLE IF NOT EXISTS `logintable` (
  `username` varchar(17) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `logintable`
--

INSERT INTO `logintable` (`username`, `password`) VALUES
('k112147', 'fast'),
('k112148', 'fast1');

-- --------------------------------------------------------

--
-- Table structure for table `registercomplaint`
--

CREATE TABLE IF NOT EXISTS `registercomplaint` (
  `token_no` int(6) NOT NULL AUTO_INCREMENT,
  `user_id` varchar(30) NOT NULL,
  `subject` varchar(25) NOT NULL,
  `dept` varchar(20) NOT NULL,
  `msg` varchar(500) NOT NULL,
  PRIMARY KEY (`token_no`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=111126 ;

--
-- Dumping data for table `registercomplaint`
--

INSERT INTO `registercomplaint` (`token_no`, `user_id`, `subject`, `dept`, `msg`) VALUES
(111117, 'k112147', 'Forgot password', 'Computer Science', 'Dear Sir I have forgot my password. please issue me new one.'),
(111118, 'k112147', 'ID CARD LOST', 'Computer Science', 'ic card lost Description'),
(111119, 'k112147', 'ID CARD LOST', 'Computer Science', 'My id card lost, Issue me another one.'),
(111120, 'k112147', 'EDU', 'EDuCATION', 'HAHAHAHAHAHAH'),
(111121, 'k112147', 'EDU', 'EDuCATION', 'HAHAHAHAHAHAH'),
(111122, 'k112147', 'EDU', 'EDuCATION', 'HAHAHAHAHAHAH'),
(111123, 'k112147', 'HERA', 'EDuCATION', 'HAHAHAHAHAHAHKDKFNVJNJV'),
(111124, 'k112148', 'Remid', 'Electrical Engineeri', 'Dear Sir/Madam,\r\n\r\nI was suffering from fever and could not attempt mid2. Please allow me to take mid again.\r\n\r\nThanks'),
(111125, 'k112147', 'Name', 'Select Department', 'Description');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
