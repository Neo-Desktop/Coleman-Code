CREATE TABLE `com330_data` (
 `id` bigint(32) NOT NULL AUTO_INCREMENT,
 `firstName` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `lastName` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Address1` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Address2` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `City` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `State` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `E-Mail` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Password` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Color` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Sports` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `Cities` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `uploadfile` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 `renamedfile` varchar(256) COLLATE utf8_bin NOT NULL DEFAULT '',
 PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='Project3