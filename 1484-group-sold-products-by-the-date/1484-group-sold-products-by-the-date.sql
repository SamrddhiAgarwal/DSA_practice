# Write your MySQL query statement below
select sell_date, count(distinct product) as num_sold, group_concat(distinct product order by product ) as products
From Activities group by sell_date order by sell_date
--  group_concat(distinct product order by product ) as products order by is use because lexicology is written