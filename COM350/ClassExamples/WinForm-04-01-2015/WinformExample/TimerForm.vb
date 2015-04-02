Public Class TimerForm

    Private executionTimer As New Stopwatch()
    Private index As Integer
    Private objVariable As Object
    Private strVariable As String
    Private dtVariable As DateTime

    ' Explict = 20.0916
    Private Sub TimerForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        textboxImplicit.Text = RunImplicit.ToString()
        textboxExplicit.Text = RunExplicit.ToString()

        'Dim myStudent As Student = New Student()
        'myStudent.FirstName = "Joe"
        'myStudent.LastName = "Smith"
        'Dim p As Person = DirectCast(myStudent, Person)

        'Dim p As Object = New Person With {.FirstName = "Joe", .LastName = "Smith"}
        'Dim s As Student = CType(p, Student)





    End Sub

    Private Function RunImplicit() As Double
        If objVariable Is Nothing Then
            objVariable = New Object()
        End If
        executionTimer.Start()

        For i As Integer = 0 To 100000
            strVariable = "About Visual Basic" & Chr(i Mod 64)
            dtVariable = #12/11/2012#
            ' objVariable.AddSeconds(1)
        Next

        executionTimer.Stop()

        Return executionTimer.Elapsed.TotalMilliseconds()
    End Function

    Private Function RunExplicit() As Double
        executionTimer.Start()

        For i As Integer = 0 To 100000
            objVariable = "About Visual Basic" & Chr(i Mod 64)
            objVariable = #12/11/2012#
            objVariable.AddSeconds(1)
        Next

        executionTimer.Stop()

        Return executionTimer.Elapsed.TotalMilliseconds()
    End Function

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles Label2.Click

    End Sub
End Class