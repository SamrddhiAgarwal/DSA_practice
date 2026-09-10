-- # Write your MySQL query statement below
-- SELECT user_id, name, mail
-- FROM Users
-- WHERE mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode[.]com$' COLLATE utf8mb4_bin;

# Write your MySQL query statement below
-- select * from Users where mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$' and mail like binary '%@leetcode.com';

-- REGEXP_LIKE(mail, pattern, 'c')
SELECT * 
FROM Users
WHERE REGEXP_LIKE (
    mail,
    '^[A-Za-z][0-9A-Za-z_.-]*@leetcode\\.com$',
    'c'
)
