async function fetchTodos() {
  const response = await (await fetch("https://jsonplaceholder.typicode.com/todos")).json();

  console.log(response);
  response.forEach(i => {
    console.log(i);
  });
}

fetchTodos();