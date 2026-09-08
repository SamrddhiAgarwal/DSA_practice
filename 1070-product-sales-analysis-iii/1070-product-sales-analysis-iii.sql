-- # Write your MySQL query statement below
-- select s.product_id,s.year as first_year,s.quantity,s.price
-- from Sales s
-- join
-- -- (select product_id,min(year) as year,quantity,price
-- (select product_id,min(year) as year
-- from Sales
-- group by product_id)f
-- ON s.product_id=f.product_id and s.year=f.year

-- # Write your MySQL query statement below
-- select product_id, s.year as first_year, quantity, price
-- from Sales as s
-- where (sale_id, product_id, year)()


select product_id, s.year as first_year, quantity as quantity, price
from Sales as s
where (product_id, s.year)
in 
(select product_id, min(year) as first_year from Sales
group by product_id)