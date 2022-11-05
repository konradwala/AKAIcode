import React from "react";
import Scores from "./Scores";
import { Route, Routes } from 'react-router-dom'



function Router() {
  return (
    <div>
     <Routes>
      
      <Route path='/score' element = {<Scores />}/>
     </Routes>
    </div>
  );
}

export default Router;
