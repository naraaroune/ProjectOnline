SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

CREATE DATABASE IF NOT EXISTS `projectonline` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `projectonline`;

DROP TABLE IF EXISTS `user`;
CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(11) NOT NULL AUTO_INCREMENT,
  `lastname` varchar(50) DEFAULT NULL,
  `firstname` varchar(50) DEFAULT NULL,
  `username` varchar(50) DEFAULT NULL,
  `password` varchar(150) DEFAULT NULL,
  `location` varchar(254) DEFAULT NULL,
  `email` varchar(64) DEFAULT NULL,
  `url` text,
  `company` varchar(64) DEFAULT NULL,
  `lastConnexion` varchar(18) DEFAULT NULL,
  PRIMARY KEY (`id_user`),
  KEY `id_user` (`id_user`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=20 ;

INSERT INTO `user` (`id_user`, `lastname`, `firstname`, `username`, `password`, `location`, `email`, `url`, `company`, `lastConnexion`) VALUES
(17, 'BOUSSAADIA', 'Amir', 'abou123', 'e10adc3949ba59abbe56e057f20f883e', 'France', 'amir.boussaadia@gmail.com', '', '', '13/07/2014 11:06:2'),
(18, 'nara', 'Eric', 'eric', 'e10adc3949ba59abbe56e057f20f883e', 'inde', 'naraaroune@yahoo.fr', 'eric.com', 'pondicherry', '13/07/2014 20:20:3'),
(19, 'niaz', 'Adil', 'adil', 'e10adc3949ba59abbe56e057f20f883e', 'pakistan', 'adil_niaz@gmail.fr', 'adil.fr', 'islamanad', '13/07/2014 23:31:1');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
