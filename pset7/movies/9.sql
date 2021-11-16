SELECT DISTINCT(people.name)
FROM stars
JOIN movies ON movies.id = movie_id
JOIN people ON people.id = person_id
WHERE movies.year = 2004
ORDER BY people.birth;