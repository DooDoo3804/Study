import React, { Component } from 'react'

class HeaderComponent extends Component {
  constructor(props) {
    super(props)
    this.state = {

    }
  }

  render() {
    return (
      <div>
        <header>
          <nav className='navbar navbar-expand-md navbar-dark bg-dark'>
            <div><a href='/' className='navbar-brand'>Employee Management App</a></div>
            <div><a href='/employees' className='navbar-brand'>Employees</a></div>
            <div><a href='/add-employee' className='navbar-brand'>Add Employee</a></div>
          </nav>
        </header>
      </div>
    )
  }
}

export default HeaderComponent
