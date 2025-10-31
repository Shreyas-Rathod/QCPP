
select s.product_id, s.year as first_year, s.quantity, s.price 
from Sales as s
join (
    select product_id, min(year) as year
    from Sales
    group by product_id
) as t
on t.product_id = s.product_id and t.year = s.year;

