const todos = [
  {
    title: "Todo 1",
    description: "eve git"
  },
  {
    title: "Todo 1",
    description: "video çekimi"
  },
  {
    title: "Todo 1",
    description: "gitar çal"
  }
]

let todoListEl = document.getElementById("todoList");

function todoList(){
  setTimeout(() => {
    let todoItems = "";
    todos.forEach((todo)=>{
      todoItems += `
        <li>
          <b>${todo.title}</b>
          <p>${todo.description}</p>
        </li>`
    });
    todoListEl.innerHTML = todoItems;
  }, 1000);
}

function pushTodo(todo) {
  return new Promise((resolve, reject) => {

  setTimeout(() => {
    todos.push(todo);

    const error = false;
    if (!error) resolve(todos); else reject('Somethings wrong!')

  }, 2000);

  });
}

const todo4 = {
  title: "Todo 4",
  description: "başka bişey yap"
}

pushTodo(todo4)
  .then( response => {
    todoList();
    console.log("New List is Constrcuted:");
    console.log(todos);
  })
  .catch( e => console.error(e));

  // Promise all

  // const p1 = Promise.resolve("P1");
  // const p2 = new Promise( (resolve,reject) =>
  //   setTimeout(() => resolve("2. Promise"), 2000)
  // )

  // const p3 = 1212;

  // const p4 = fetch('https://jsonplaceholder.typicode.com/todos/3').then(response => response.json());

  // Promise.all([p1,p2,p3,p4]).then(
  //   (response) => {
  //     console.log(response, response[3].title)
  //   }
  // )