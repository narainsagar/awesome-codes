-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 16, 2014 at 02:08 AM
-- Server version: 5.5.32
-- PHP Version: 5.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `cn_project`
--
CREATE DATABASE IF NOT EXISTS `cn_project` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `cn_project`;

-- --------------------------------------------------------

--
-- Table structure for table `franchise_branches`
--

CREATE TABLE IF NOT EXISTS `franchise_branches` (
  `branch_code` int(6) NOT NULL AUTO_INCREMENT,
  `branch_area_name` varchar(45) NOT NULL,
  `area_code` varchar(45) NOT NULL,
  `city` varchar(45) NOT NULL,
  `country` varchar(45) NOT NULL,
  `address` varchar(45) NOT NULL,
  PRIMARY KEY (`branch_code`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=111113 ;

--
-- Dumping data for table `franchise_branches`
--

INSERT INTO `franchise_branches` (`branch_code`, `branch_area_name`, `area_code`, `city`, `country`, `address`) VALUES
(111111, 'Karimabad', '75300', 'Karachi', 'Pakistan', 'C-13, Block-4, F.B Area Karimabad.'),
(111112, 'Karimabad', '75400', 'Karachi', 'Pakistan', 'B-15, Block-5, F.B Area Aisha Manzil.');

-- --------------------------------------------------------

--
-- Table structure for table `sfo`
--

CREATE TABLE IF NOT EXISTS `sfo` (
  `mobile_no` varchar(45) NOT NULL,
  `franchise_branch_code` int(6) NOT NULL,
  `cnic_no` varchar(15) NOT NULL,
  `full_name` varchar(45) NOT NULL,
  `email_id` varchar(45) NOT NULL,
  `passwd` varchar(45) NOT NULL,
  `transaction_pin` int(6) NOT NULL,
  `available_balance` int(10) unsigned NOT NULL,
  PRIMARY KEY (`mobile_no`),
  KEY `SFO_ibfk_1` (`franchise_branch_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `sfo`
--

INSERT INTO `sfo` (`mobile_no`, `franchise_branch_code`, `cnic_no`, `full_name`, `email_id`, `passwd`, `transaction_pin`, `available_balance`) VALUES
('923123841914', 111111, '44205-5719185-3', 'Narain Menghwar', 'k112368@nu.edu.pk', '12345', 123123, 3950);

-- --------------------------------------------------------

--
-- Table structure for table `sfo_transactions`
--

CREATE TABLE IF NOT EXISTS `sfo_transactions` (
  `transac_id` int(10) NOT NULL AUTO_INCREMENT,
  `SFO_mobile_no` varchar(45) NOT NULL,
  `shop_keeper_mobile_no` varchar(45) NOT NULL,
  `transac_amount` int(10) unsigned NOT NULL,
  `transac_date` date NOT NULL,
  PRIMARY KEY (`transac_id`),
  KEY `SFO_transactions_ibfk_1` (`SFO_mobile_no`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `sfo_transactions`
--

INSERT INTO `sfo_transactions` (`transac_id`, `SFO_mobile_no`, `shop_keeper_mobile_no`, `transac_amount`, `transac_date`) VALUES
(1, '923123841914', '923072052203', 5000, '0000-00-00'),
(2, '923123841914', '923072052203', 5000, '0000-00-00'),
(3, '923123841914', '923072052203', 5000, '0000-00-00'),
(4, '923123841914', '923072052203', 5000, '0000-00-00'),
(5, '923123841914', '923072052203', 5000, '0000-00-00'),
(6, '923123841914', '923072052203', 5000, '0000-00-00'),
(7, '923123841914', '923443747156', 5000, '0000-00-00');

-- --------------------------------------------------------

--
-- Table structure for table `shop_keeper`
--

CREATE TABLE IF NOT EXISTS `shop_keeper` (
  `mobile_no` varchar(45) NOT NULL,
  `SFO_mobile_no` varchar(45) NOT NULL,
  `cnic_no` varchar(15) NOT NULL,
  `full_name` varchar(45) NOT NULL,
  `email_id` varchar(45) NOT NULL,
  `passwd` varchar(45) NOT NULL,
  `shop_name` varchar(45) NOT NULL,
  `address` varchar(45) NOT NULL,
  `city_name` varchar(45) NOT NULL,
  `country_name` varchar(45) NOT NULL,
  `security_question` varchar(255) NOT NULL,
  `security_ans` varchar(45) NOT NULL,
  `transaction_pin` int(6) NOT NULL,
  `available_balance` int(10) unsigned NOT NULL,
  PRIMARY KEY (`mobile_no`),
  KEY `shop_keeper_ibfk_1` (`SFO_mobile_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `shop_keeper`
--

INSERT INTO `shop_keeper` (`mobile_no`, `SFO_mobile_no`, `cnic_no`, `full_name`, `email_id`, `passwd`, `shop_name`, `address`, `city_name`, `country_name`, `security_question`, `security_ans`, `transaction_pin`, `available_balance`) VALUES
('923072052203', '923123841914', '44205-0796828-1', 'Prem Chand', 'prem_chand@gmail.com', 'prem123', 'Prem Comunication', 'WARD#8, JHOL', 'Jhol, Sanghar', 'PK', 'C', 'Apple', 123456, 72900),
('923443747156', '923123841914', '44205-0796828-3', 'Lal Chand', 'lal_chand@gmail.com', 'lal123', 'Prem Comunication', 'WARD#8, JHOL', 'Jhol, Sanghar', 'PK', 'C', 'Apple', 123456, 45150);

-- --------------------------------------------------------

--
-- Table structure for table `shop_keeper_orders`
--

CREATE TABLE IF NOT EXISTS `shop_keeper_orders` (
  `shop_keeper_mobile_no` varchar(45) NOT NULL,
  `SFO_mobile_no` varchar(45) NOT NULL,
  `available_balance` int(10) unsigned NOT NULL,
  `order_amount` int(10) unsigned NOT NULL,
  `order_date` date NOT NULL,
  `order_status` tinyint(1) NOT NULL DEFAULT '0',
  `order_timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  KEY `shop_keeper_orders_ibfk_1` (`shop_keeper_mobile_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `shop_keeper_orders`
--

INSERT INTO `shop_keeper_orders` (`shop_keeper_mobile_no`, `SFO_mobile_no`, `available_balance`, `order_amount`, `order_date`, `order_status`, `order_timestamp`) VALUES
('923072052203', '923123841914', 40000, 5000, '0000-00-00', 1, '2014-05-08 12:15:27'),
('923443747156', '923123841914', 40000, 10000, '0000-00-00', 1, '2014-05-15 22:46:16'),
('923443747156', '923123841914', 45150, 1000, '0000-00-00', 0, '2014-05-15 23:04:44');

-- --------------------------------------------------------

--
-- Table structure for table `shop_keeper_transactions_receive`
--

CREATE TABLE IF NOT EXISTS `shop_keeper_transactions_receive` (
  `trx_id` int(8) NOT NULL,
  `shop_keeper_mobile_no` varchar(45) NOT NULL,
  `trx_amount` int(10) unsigned NOT NULL,
  `trx_date` date NOT NULL,
  `trx_timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  KEY `shop_keeper_transactions_receive_ibfk_1` (`trx_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `shop_keeper_transactions_receive`
--

INSERT INTO `shop_keeper_transactions_receive` (`trx_id`, `shop_keeper_mobile_no`, `trx_amount`, `trx_date`, `trx_timestamp`) VALUES
(10000001, '923072052203', 2000, '0000-00-00', '2014-05-07 00:21:34'),
(10000002, '923072052203', 5000, '0000-00-00', '2014-05-07 00:43:03'),
(10000004, '923072052203', 1000, '0000-00-00', '2014-05-11 19:11:42');

-- --------------------------------------------------------

--
-- Table structure for table `shop_keeper_transactions_send`
--

CREATE TABLE IF NOT EXISTS `shop_keeper_transactions_send` (
  `trx_id` int(8) NOT NULL AUTO_INCREMENT,
  `shop_keeper_mobile_no` varchar(45) NOT NULL,
  `trx_amount` int(10) unsigned NOT NULL,
  `trx_date` date NOT NULL,
  `sender_cnic` varchar(15) NOT NULL,
  `sender_mobile` varchar(45) NOT NULL,
  `security_pin` int(4) NOT NULL,
  `receiver_cnic` varchar(15) NOT NULL,
  `receiver_mobile` varchar(45) NOT NULL,
  `trx_timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`trx_id`),
  KEY `shop_keeper_transactions_send_ibfk_1` (`shop_keeper_mobile_no`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10000007 ;

--
-- Dumping data for table `shop_keeper_transactions_send`
--

INSERT INTO `shop_keeper_transactions_send` (`trx_id`, `shop_keeper_mobile_no`, `trx_amount`, `trx_date`, `sender_cnic`, `sender_mobile`, `security_pin`, `receiver_cnic`, `receiver_mobile`, `trx_timestamp`) VALUES
(10000001, '923072052203', 2000, '2014-05-07', '44205-5719185-3', '923123841914', 1234, '44205-5719185-4', '923123841917', '2014-05-07 03:38:20'),
(10000002, '923072052203', 5000, '2014-05-07', '44205-5815127-8', '923443747156', 1122, '44205-5815127-5', '923463626816', '2014-05-07 13:31:15'),
(10000003, '923072052203', 10000, '0000-00-00', '44205-0796828-1', '923463626816', 1111, '44205-0796828-2', '923463626814', '2014-05-06 23:31:46'),
(10000004, '923443747156', 1000, '0000-00-00', '4420657181759', '923063054848', 1234, '4420657181145', '923442021005', '2014-05-11 15:19:31'),
(10000005, '923443747156', 2000, '0000-00-00', '4420456897893', '923123841915', 1122, '4420456897145', '923123841913', '2014-05-11 15:28:38'),
(10000006, '923072052203', 1000, '0000-00-00', '4420187451896', '923463626816', 1144, '4420187451145', '923463626815', '2014-05-11 18:34:42');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `sfo`
--
ALTER TABLE `sfo`
  ADD CONSTRAINT `sfo_ibfk_1` FOREIGN KEY (`franchise_branch_code`) REFERENCES `franchise_branches` (`branch_code`);

--
-- Constraints for table `sfo_transactions`
--
ALTER TABLE `sfo_transactions`
  ADD CONSTRAINT `sfo_transactions_ibfk_1` FOREIGN KEY (`SFO_mobile_no`) REFERENCES `sfo` (`mobile_no`);

--
-- Constraints for table `shop_keeper`
--
ALTER TABLE `shop_keeper`
  ADD CONSTRAINT `shop_keeper_ibfk_1` FOREIGN KEY (`SFO_mobile_no`) REFERENCES `sfo` (`mobile_no`);

--
-- Constraints for table `shop_keeper_orders`
--
ALTER TABLE `shop_keeper_orders`
  ADD CONSTRAINT `shop_keeper_orders_ibfk_1` FOREIGN KEY (`shop_keeper_mobile_no`) REFERENCES `shop_keeper` (`mobile_no`);

--
-- Constraints for table `shop_keeper_transactions_receive`
--
ALTER TABLE `shop_keeper_transactions_receive`
  ADD CONSTRAINT `shop_keeper_transactions_receive_ibfk_1` FOREIGN KEY (`trx_id`) REFERENCES `shop_keeper_transactions_send` (`trx_id`);

--
-- Constraints for table `shop_keeper_transactions_send`
--
ALTER TABLE `shop_keeper_transactions_send`
  ADD CONSTRAINT `shop_keeper_transactions_send_ibfk_1` FOREIGN KEY (`shop_keeper_mobile_no`) REFERENCES `shop_keeper` (`mobile_no`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
