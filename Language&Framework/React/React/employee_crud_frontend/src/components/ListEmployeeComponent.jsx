import React, { Component } from 'react'
import EmployeeService from '../services/EmployeeService'

export default class ListEmployeeComponent extends Component {
    

    constructor(props) {
        super(props)

        this.state = {
            employees: []
        }
        this.addEmployee = this.addEmployee.bind(this)
        this.editEmployee = this.editEmployee.bind(this)
    }
    componentDidMount () {
        EmployeeService.getEmployees().then((res) => {
            this.setState({ employees: res.data});
        })
    }
    
    addEmployee () {
        // react-router-dom v6 부터는 this.props.history.push() 불가능
        // useNavigate 해야됨
        this.props.history.push('/add-employee/-1');
    }

    editEmployee(id) {
        this.props.history.push(`/add-employee/${id}`);
    }

  render() {
    return (
      <div>
        <h2 className='text-center'>EmployeeList</h2>
        <button className='btn btn-primary' onClick={this.addEmployee}>Add Employee</button>
        <div className='row'>
            <table className='table table-striped table-bordered'>
                <thead>
                    <tr>
                        <th>Employee First Name</th>
                        <th>Employee Last Name</th>
                        <th>Employee Email</th>
                        <th>Employee Actions</th>
                    </tr>
                </thead>
                <tbody>
                    {
                        this.state.employees.map (
                            employee =>
                            <tr key={employee.id}>
                                <td> {employee.firstName} </td>
                                <td> {employee.lastName} </td>
                                <td> {employee.email} </td>
                                <td> <button className='btn btn-info text-white' onClick={()=> this.editEmployee(employee.id)} >UPDATE</button> </td>
                            </tr>
                        )
                    }
                </tbody>
            </table>
        </div>
      </div>
    )
  }
}
