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

function pushTodo(todo, callback) {
  setTimeout(() => {
    todos.push(todo);
    callback();
  }, 2000);
}

const todo4 = {
  title: "Todo 4",
  description: "başka bişey yap"
}

pushTodo(todo4, todoList);

// todoList();