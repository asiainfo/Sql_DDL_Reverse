ALTER TABLE `bs`.`cm_contacts`
/*DROP COLUMN `region_id`,*/
#MODIFY COLUMN `contacts_status`  varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `contacts_id`,
ADD COLUMN `test1`  varchar(255) NOT NULL AFTER `state`,
#MODIFY COLUMN `test2`  varchar(255) NULL AFTER `test1`,
ADD INDEX `idx_test3` (`status_date`, `create_op_id`, `create_org_id`, `op_id`) ;

ALTER TABLE `cm_custacct_bill`
ADD COLUMN `test`.`bs`.`eboss1`  double NULL AFTER `state`,
ADD COLUMN `eboss3`  double NULL,
ADD COLUMN `eboss2`  timestamp NULL ON UPDATE CURRENT_TIMESTAMP AFTER `eboss1`;

ALTER TABLE `cm_contacts` ADD CONSTRAINT `fk_001` FOREIGN KEY (`contacts_id`, `contacts_status`, `status_date`) REFERENCES `businesscommon`.`bi_int_address` (`intact_place_id`, `intact_id`, `addr_id`);

CREATE TABLE NewTable (
`eboss01`  tinyint NULL ,
`eboss02`  smallint NULL ,
`field03`  mediumint NULL ,
`f04`  int NULL ,
`f05`  integer NULL ,
`f06`  bigint NULL ,
`f07`  bit NULL ,
`f08`  real NULL ,
`f09`  double NULL ,
`f10`  float NULL ,
`f11`  decimal NULL ,
`f12`  numeric(2,0) NULL ,
`f13`  char(133) NULL ,
`f14`  varchar(255) NULL ,
`f15`  date NULL ,
`f16`  time NULL ,
`f17`  year NULL ,
`f18`  timestamp NULL ON UPDATE CURRENT_TIMESTAMP ,
`f19`  tinyblob NULL ,
`f20`  blob NULL ,
`f21`  mediumblob NULL ,
`f22`  longblob NULL ,
`f23`  tinytext NULL ,
`f24`  text NULL ,
`f25`  mediumtext NULL ,
`f26`  longtext NULL ,
`f27`  enum('') NULL ,
`f28`  set('') NULL DEFAULT '' ,
`f29`  binary(255) NULL ,
`f30`  varbinary(255) NULL ,
`f31`  point NULL ,
`f32`  linestring NULL ,
`f33`  polygon NULL ,
`f34`  geometry NULL ,
`f35`  multipoint NULL ,
`f36`  multilinestring NULL ,
`f37`  multipolygon NULL ,
`f38`  geometrycollection NULL ,
INDEX `idx_01` (`eboss01`, `field03`, `f04`) ,
UNIQUE INDEX `pk_01` (`f05`) 
)
;

create unique index idx_test_create on NewTable ( f30,
f31, f32);
CREATE 
VIEW `NewView`AS 
SELECT
agent_cont_assoc.AGENT_CONT_ASSOC_ID,
agent_cont_assoc.CREATE_DATE,
agent_cont_assoc.DONE_DATE
FROM 
agent_cont_assoc 
WHERE
agent_cont_assoc.OP_ID = 21
GROUP BY
agent_cont_assoc.ORG_ID
ORDER BY
agent_cont_assoc.CREATE_DATE ASC
LIMIT 1, 10 ;
/*CREATE EVENT `NewEvent`
ON SCHEDULE AT CURRENT_TIMESTAMP + INTERVAL 1 MINUTE
ON COMPLETION NOT PRESERVE
ENABLE
DO
SELECT * from base.ae_abo;*/
