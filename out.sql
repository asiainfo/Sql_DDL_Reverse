ALTER TABLE bs.cm_contacts
    DROP COLUMN test1,
    DROP INDEX idx_test3
;
ALTER TABLE cm_custacct_bill
    DROP COLUMN test.bs.eboss1,
    DROP COLUMN eboss3,
    DROP COLUMN eboss2
;
ALTER TABLE cm_contacts
    DROP FOREIGN KEY fk_001
;
DROP TABLE NewTable
;
ALTER TABLE NewTable
     DROP INDEX idx_test_create
;
DROP VIEW NewView
;
