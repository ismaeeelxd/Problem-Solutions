SELECT t.id FROM Weather as t
JOIN Weather as t2 ON t.recordDate - t2.recordDate = 1 WHERE 
t.temperature > t2.temperature;
