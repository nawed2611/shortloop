import Comment from "./Comment";
import Data from "./data.json";

function App() {
  return (
    <div className="flex flex-col items-center justify-center min-h-[100vh]">
      <Comment
        name={Data.name}
        image={Data.image}
        comment={Data.comment}
        comments={Data.comments}
      />
    </div>
  )
}

export default App
