Imports MySql.Data.MySqlClient

Module Module1

    Sub Main()

        Dim connectionString = "server=127.0.0.1;database=ad77260;uid=ad77260;pwd=90dd0e54;pooling=false;AllowZeroDateTime=True;"
        Dim MysqlConn As MySqlConnection = New MySqlConnection(connectionString)
        Try
            Console.WriteLine("Attempting to open to {0}", connectionString)
            MysqlConn.Open()

            Dim MySqlCommand As MySqlCommand = New MySqlCommand("Select * from com330_data", MysqlConn)
            Dim dr As MySqlDataReader = MySqlCommand.ExecuteReader()

            If dr.HasRows Then
                While dr.Read()
                    Console.WriteLine("{0}, {1}, {2}, {3}", dr(0), dr(1), dr(2), dr(3))
                End While
            End If

            MysqlConn.Close()
            MysqlConn.Dispose()
        Catch ex As Exception
            Console.WriteLine("Caught exception attempting to open mysqlconn")
        End Try

        Console.ReadKey()

    End Sub

End Module
