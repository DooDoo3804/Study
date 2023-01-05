import './App.css';
import ListEmployeeComponent from './components/ListEmployeeComponent';
import HeaderComponent from './components/HeaderComponent';
import FooterComponent from './components/FooterComponent';
import {BrowserRouter as Router, Route, Switch} from 'react-router-dom'
import CreaeteEmployeeComponent from './components/CreaeteEmployeeComponent';
import UpdateEmployeeComponent from './components/UpdateEmployeeComponent';
function App() {
  return (
    <div>
      <Router>
        <HeaderComponent/>
        <div className='container'>
          {/*  react-router-dom v6 부터는 Switch대신 Routes를 사용 */}
          {/*  component 대신에 element 사용 */}
          <Switch>
            <Route path = "/" exact={true} component = {ListEmployeeComponent}></Route>
            <Route path = "/employees" component = {ListEmployeeComponent}></Route>
            <Route path = "/add-employee" component = {CreaeteEmployeeComponent}></Route>
            <Route path = "/update-employee/:id" component = {UpdateEmployeeComponent}></Route>
          </Switch>
        </div>
        <FooterComponent/>
      </Router>
    </div>
    
  );
}

export default App;
