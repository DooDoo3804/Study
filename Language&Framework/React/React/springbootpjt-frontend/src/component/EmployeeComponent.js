
import React, { useEffect, useState } from 'react'
import EmployeeService from '../services/EmployeeService'

//rfc
function EmployeeComponent() {

  const [employees, setEmployees] = useState([])

  useEffect(() => {
    getEmployees()
  }, [])

  const getEmployees = () => {
    EmployeeService.getEmployees().then((response) => {

      setEmployees(response.data);
      console.log(response.data);
    });
  }
  return (
    <div className='container'>
      <h1 className='text-center'> Employees List </h1>
      <table className='table table-striped'>
        <thead>
          <tr>
            <th> Employee Id </th>
            <th> First Name </th>
            <th> Last Name </th>
            <th> Email </th>
          </tr>
        </thead>
        <tbody>
          {
            employees.map(
              employee =>
              <tr key = {employee.id}>
                <td> {employee.id} </td>
                <td> {employee.firstName} </td>
                <td> {employee.lastName} </td>
                <td> {employee.email} </td>
              </tr>
            )
          }
        </tbody>
      </table>

    </div>
  )
}

export default EmployeeComponent