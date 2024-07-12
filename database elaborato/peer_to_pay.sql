-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Creato il: Lug 12, 2024 alle 10:03
-- Versione del server: 10.4.28-MariaDB
-- Versione PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `peer_to_pay`
--

-- --------------------------------------------------------

--
-- Struttura della tabella `bank_account`
--

CREATE TABLE `bank_account` (
  `id` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `account_number` text NOT NULL,
  `expiration_date` text NOT NULL,
  `cvv` text NOT NULL,
  `balance` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `bank_account`
--

INSERT INTO `bank_account` (`id`, `id_user`, `account_number`, `expiration_date`, `cvv`, `balance`) VALUES
(5, 4, '4333111122223333', '05/25', '123', 5215.5),
(6, 5, '4333555588887777', '02/28', '456', 217.80999999999997);

-- --------------------------------------------------------

--
-- Struttura della tabella `temporary_identifier`
--

CREATE TABLE `temporary_identifier` (
  `id` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `code` text NOT NULL,
  `expiration_date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `temporary_identifier`
--

INSERT INTO `temporary_identifier` (`id`, `id_user`, `code`, `expiration_date`) VALUES
(14, 4, '50073', '2024-07-12 09:21:01'),
(15, 5, '75249', '2024-07-11 08:57:55'),
(16, 6, '97801', '2024-07-11 09:27:07');

-- --------------------------------------------------------

--
-- Struttura della tabella `transaction`
--

CREATE TABLE `transaction` (
  `id` int(11) NOT NULL,
  `id_sender` int(11) NOT NULL,
  `id_receiver` int(11) NOT NULL,
  `amount` text NOT NULL,
  `date` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `transaction`
--

INSERT INTO `transaction` (`id`, `id_sender`, `id_receiver`, `amount`, `date`) VALUES
(1, 5, 4, '100.00', '2024-07-11 08:50:40'),
(2, 5, 4, '0.46', '2024-07-11 08:58:41'),
(3, 5, 4, '0.08', '2024-07-11 08:59:23'),
(4, 5, 4, '1.10', '2024-07-11 09:00:35'),
(5, 5, 4, '10.55', '2024-07-11 09:01:23'),
(6, 4, 6, '15.00', '2024-07-11 09:12:58');

-- --------------------------------------------------------

--
-- Struttura della tabella `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `email` text NOT NULL,
  `psw` text NOT NULL,
  `first_name` text NOT NULL,
  `last_name` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dump dei dati per la tabella `user`
--

INSERT INTO `user` (`id`, `email`, `psw`, `first_name`, `last_name`) VALUES
(3, 'ciao@gmail.com', '4hgrdugr4', 'Ferrp', 'Tizi'),
(4, 'edoardo@gmail.com', '456789', 'Edoardo', 'Nero'),
(5, 'filippo@gmail.com', '456789', 'Filippo', 'Test'),
(6, 'giovanni@gmail.com', '456789', 'Giovanni', 'Caselli');

--
-- Indici per le tabelle scaricate
--

--
-- Indici per le tabelle `bank_account`
--
ALTER TABLE `bank_account`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `temporary_identifier`
--
ALTER TABLE `temporary_identifier`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `transaction`
--
ALTER TABLE `transaction`
  ADD PRIMARY KEY (`id`);

--
-- Indici per le tabelle `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT per le tabelle scaricate
--

--
-- AUTO_INCREMENT per la tabella `bank_account`
--
ALTER TABLE `bank_account`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT per la tabella `temporary_identifier`
--
ALTER TABLE `temporary_identifier`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT per la tabella `transaction`
--
ALTER TABLE `transaction`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT per la tabella `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
