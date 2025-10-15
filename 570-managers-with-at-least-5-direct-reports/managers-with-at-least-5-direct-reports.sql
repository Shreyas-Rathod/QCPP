# Write your MySQL query statement below

select t2.name 
from Employee as t1 join Employee as t2 on t1.managerId = t2.id
group by t1.managerId, t2.name having count(t1.managerId) > 4 

