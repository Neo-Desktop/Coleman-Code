Public Class MainForm


    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub DefaultToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles DefaultToolStripMenuItem.Click
        Dim lnof = New OptionsForm(Me)
        lnof.Show()
    End Sub

    Public Sub SubFormCallback()
        MessageBox.Show("Do we halt here", "I dunno", MessageBoxButtons.OK, MessageBoxIcon.Exclamation)
    End Sub


End Class
