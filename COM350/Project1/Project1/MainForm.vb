Public Class MainForm

    Protected list As New List(Of FileData)

    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub DefaultToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles DefaultToolStripMenuItem.Click
        Dim lnof = New OptionsForm()
        If (lnof.ShowDialog() = Windows.Forms.DialogResult.OK) Then
            RefreshData()
        End If
    End Sub

    Public Sub RefreshData()
        ' MessageBox.Show("Do we halt here", "I dunno", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
        For Each foundFile As String In My.Computer.FileSystem.GetFiles(Options.Directory)

        Next
    End Sub

End Class
