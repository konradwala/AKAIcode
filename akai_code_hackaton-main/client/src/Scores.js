import React from "react";
import { useEffect, useState } from "react";
import axios from 'axios'
import Table from 'react-bootstrap/Table';
import './Scores.css'

const api = axios.create({
  baseURL: 'http://localhost:5000',
  withCredentials: true,

})

const Scores = () => {

    const [players, setPlayers] = useState([])

    useEffect(() => {
        try {
          api.get('/score').then((response) => {
            setPlayers(response.data)
          })
        } catch (error) {
          console.log(error)
        }
      }, [])





    return ( 
        <div>
            <table className="table">
                <div className="opis">
                        <div className='player-des'>
                        <h4 className='player-des'>player</h4>
                        </div>
                        <div className='player-des'>
                        <h4 className='player-des'>Game 1</h4>
                        </div>
                        <div className='player-des'>
                        <h4 className='player-des'>Game 2</h4>
                        </div>
                        <div className='player-des'>
                        <h4 className='player-des'>Game 3</h4>
                        </div>
                        <div className='player-des'>
                        <h4 className='player-des'>Game 4</h4>
                        </div>
                </div>
                </table>
                {players.map((player) => (
                <table className=" table">
                <div className="results">
                    <div className="div-mrg">
                        <h4 className='player-username'>{player.username}</h4>
                    </div>
                    <div className="div-mrg">
                        <h4 className='player-game'>{player.game1}</h4>
                    </div>
                    <div className="div-mrg">
                        <h4 className='player-game'>{player.game2}</h4>
                    </div>
                    <div className="div-mrg">
                        <h4 className='player-game'>{player.game3}</h4>
                    </div>
                    <div className="div-mrg">
                        <h4 className='player-game'>{player.game4}</h4>
                    </div>
                </div>
                </table>
            ))}
            
        </div>
     );
}
 
export default Scores;