SELECT title, ratings.rating
FROM movies
JOIN ratings ON movie_id = movies.id
WHERE year = 2010
ORDER BY ratings.rating DESC, title ASC;
