SELECT DISTINCT(people.name)
FROM directors
JOIN movies ON movies.id = movie_id
JOIN people ON people.id = person_id
WHERE movie_id IN (SELECT id
                   FROM movies
                   WHERE id IN (SELECT movie_id
                                FROM ratings
                                WHERE rating >= 9.0));