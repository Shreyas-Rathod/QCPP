# Write your MySQL query statement below

select E1.unique_id, E.name from EmployeeUNI as E1 right join Employees as E on E1.id = E.id;
