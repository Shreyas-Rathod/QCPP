# Write your MySQL query statement below

select * from Cinema as s
where s.id % 2 <> 0 and s.description <> 'boring'
order by s.rating DESC;

